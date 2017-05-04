package com.kwrp.planner_gui;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.GridView;
import android.widget.TextView;
import android.widget.Toast;


import java.util.ArrayList;
import java.util.Calendar;

import static com.kwrp.planner_gui.R.id.gridview;


public class MainActivity extends AppCompatActivity {
    private Calendar currentDate;
    private ArrayList<Integer> currentDay = new ArrayList<>();


    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("calender");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        currentDate = Calendar.getInstance();
        currentDay.add(currentDate.get(Calendar.DAY_OF_MONTH));
        currentDay.add(currentDate.get(Calendar.MONTH)); // zero based
        currentDay.add(currentDate.get(Calendar.YEAR));

        final DisplayMetrics metrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(metrics);

        GridView mGridView = (GridView) findViewById(gridview);
        mGridView.setAdapter(new MonthAdapter(this, currentDay.get(1), currentDay.get(2), metrics) {
            @Override
            protected void onDate(int[] date, int position, View item) {
            }
        });

        mGridView.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {

            @Override
            public boolean onItemLongClick(AdapterView<?> arg0, View arg1,
                                           int arg2, long arg3) {
                Intent myIntent = new Intent(arg1.getContext(), DisplayDay.class); /** Class name here */
                startActivityForResult(myIntent, 0);
                return true;
            }
        });

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        //tv.setText(stringFromJNI());
        Log.d("TESTING!!!", testJNI());
        //mGridView.findViewById(1).tex = testJNI();

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

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String testJNI();
}
