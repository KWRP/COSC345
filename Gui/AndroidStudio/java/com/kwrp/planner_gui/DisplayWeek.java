package com.kwrp.planner_gui;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.BottomNavigationView;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import static com.kwrp.planner_gui.R.id.fab;

public class DisplayWeek extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display_week);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar_week);
        setSupportActionBar(toolbar);
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_week, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_display_month) {
            Intent myIntent = new Intent(this, DisplayMonth.class); /** Class name here */
            startActivity(myIntent);
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
            AlertDialog aboutDialog = createAboutDialog();
            aboutDialog.show();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    private AlertDialog createAboutDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(DisplayWeek.this);
        builder.setMessage("")
                .setTitle("About us")
                .setMessage("Master betrayed us. Wicked. Tricksy, False. We ought to " +
                        "wring his filthy little neck. Kill him! Kill him! Kill them both! " +
                        "And then we take the precious... and we be the master!");

        builder.setNeutralButton("Back", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int id) {
                dialog.dismiss();
            }
        });
        AlertDialog dialog = builder.create();
        return dialog;
    }

}
