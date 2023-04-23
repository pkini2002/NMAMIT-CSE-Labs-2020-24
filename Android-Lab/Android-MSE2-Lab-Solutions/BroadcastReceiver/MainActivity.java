package com.example.mse2android;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.graphics.Color;
import android.os.BatteryManager;
import android.os.Bundle;
import android.widget.ProgressBar;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    ConstraintLayout layout;
    ProgressBar pb;
    TextView t;
    BroadcastReceiver b;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        layout=findViewById(R.id.constlayout);
        pb=findViewById(R.id.progressBar);
        t=findViewById(R.id.textView);

        b=new BroadcastReceiver() {
            @Override
            public void onReceive(Context context, Intent intent) {
                int level=intent.getIntExtra(BatteryManager.EXTRA_LEVEL,0);
                t.setText("Battery level: "+level);
                pb.setProgress(level);

                if(level>60){
                    layout.setBackgroundColor(Color.GREEN);
                }
                else if(level>30){
                    layout.setBackgroundColor(Color.BLUE);
                }
                else{
                    layout.setBackgroundColor(Color.RED);
                }
            }
        };
    }

    @Override
    protected void onStart() {
        super.onStart();
        registerReceiver(b,new IntentFilter(Intent.ACTION_BATTERY_CHANGED));
    }

    @Override
    protected void onStop() {
        super.onStop();
        unregisterReceiver(b);
    }
}
