package com.kwrp.planner_gui;


import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
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
        setContentView(R.layout.activity_events);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        getEvents();
        ArrayAdapter<String> listAdapter = new ArrayAdapter<>(this,
                android.R.layout.simple_list_item_1,
                eventItems);
        ListView events = (ListView) findViewById(R.id.list_view_events);
        events.setAdapter(listAdapter);
    }

    protected void getEvents() {
        int cplusplusEvents = 3;
        for (int event = 0; event < cplusplusEvents; event++) {
            eventItems.add("Events o'clock");
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

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
        //noinspection SimplifiableIfStatement
        if (id == R.id.action_exit) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
