package com.kwrp.planner_gui;

import android.content.Context;
import android.graphics.Color;
import android.util.DisplayMetrics;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.List;


/**
 * Created by willy on 30/04/2017.
 * Adapted from
 * https://github.com/jrdnull/Android-Calendar-GridView-Adapter/blob/master/MonthAdapter.java
 */
public class DisplayMonth extends BaseAdapter {
    private GregorianCalendar mCalendar;
    private Calendar mCalendarToday;
    private Context currentContext;
    private DisplayMetrics displayMetrics;
    private List<String> mItems;
    private int selectedMonth;
    private int selectedYear;
    private int mDaysShown;
    private int mDaysLastMonth;
    private int mDaysNextMonth;
    private int mTitleHeight, mDayHeight;
    private final String[] mDays = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
    private final int[] mDaysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    public DisplayMonth(Context c, int month, int year, DisplayMetrics metrics) {
        currentContext = c;
        selectedMonth = month;
        selectedYear = year;
        mCalendar = new GregorianCalendar(selectedYear, selectedMonth, 1);
        mCalendarToday = Calendar.getInstance();
        displayMetrics = metrics;
        //populateMonth();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        final TextView view = new TextView(currentContext);
        view.setGravity(Gravity.CENTER_VERTICAL | Gravity.CENTER_HORIZONTAL);
        view.setText(mItems.get(position));
        view.setTextColor(Color.BLACK);
        return view;
    }

    /**
     * How many items are in the data set represented by this Adapter.
     *
     * @return Count of items.
     */
    @Override
    public int getCount() {
        return 0;
    }

    /**
     * Get the data item associated with the specified position in the data set.
     *
     * @param position Position of the item whose data we want within the adapter's
     *                 data set.
     * @return The data at the specified position.
     */
    @Override
    public Object getItem(int position) {
        return null;
    }

    /**
     * Get the row id associated with the specified position in the list.
     *
     * @param position The position of the item within the adapter's data set whose row id we want.
     * @return The id of the item at the specified position.
     */
    @Override
    public long getItemId(int position) {
        return 0;
    }

}