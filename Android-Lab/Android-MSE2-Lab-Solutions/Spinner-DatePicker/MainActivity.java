package com.example.mse2android;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.DatePicker;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {
    ArrayAdapter ad;
    DatePicker d;
    String s2[]={"CSE","ISE","ECE","EEE"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ad=new ArrayAdapter<String>(this, androidx.appcompat.R.layout.support_simple_spinner_dropdown_item,s2);
        Spinner s=findViewById(R.id.spinner);
        d=findViewById(R.id.datePicker1);
        s.setAdapter(ad);
        s.setOnItemSelectedListener(this);
    }


    @Override
    public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
        String s1=ad.getItem(i).toString();
        String dat=d.getDayOfMonth()+"-"+(d.getMonth()+1)+"-"+d.getYear();
        String tost="Joined on : "+dat+" and selected course: "+s1;
        Toast.makeText(getApplicationContext(), tost, Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onNothingSelected(AdapterView<?> adapterView) {

    }
}
