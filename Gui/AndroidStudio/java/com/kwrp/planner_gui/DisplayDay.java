package com.kwrp.planner_gui;


import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import java.util.ArrayList;



public class DisplayDay extends AppCompatActivity {
    private ArrayList<String> eventItems = new ArrayList<>();


    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("calender");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display_day);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar_day);
        setSupportActionBar(toolbar);

        getEvents();
        ArrayAdapter<String> listAdapter = new ArrayAdapter<>(this,
                android.R.layout.simple_list_item_1,
                eventItems);
        ListView events = (ListView) findViewById(R.id.list_view_events);
        events.setAdapter(listAdapter);

        EditText dateField = (EditText) findViewById(R.id.output_selected_date);
        String currentDate = jniGetCurrentDate();
        dateField.setText(currentDate);
    }

    protected void getEvents() {
        int cplusplusEvents = 3;
        for (int event = 0; event < cplusplusEvents; event++) {
            eventItems.add("Events o'clock");
        }
        String e = jniGetEvents();
        eventItems.add(e);//jniGetEvents());
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_day, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        if (id == R.id.action_display_month) {
            Intent myIntent = new Intent(this, DisplayMonth.class); /** Class name here */
            startActivity(myIntent);
            finish();
        }
        if (id == R.id.action_display_week) {
            Intent myIntent = new Intent(this, DisplayWeek.class); /** Class name here */
            startActivity(myIntent);
            //startActivityForResult(myIntent, 0);
            finish();
        }

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }
        //noinspection SimplifiableIfStatement
        if (id == R.id.action_sync) {
            return true;
        }
        //noinspection SimplifiableIfStatement
        if (id == R.id.action_about) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String jniGetEvents();
    public native String jniGetCurrentDate();
    public native Object jniGetDay();
}
