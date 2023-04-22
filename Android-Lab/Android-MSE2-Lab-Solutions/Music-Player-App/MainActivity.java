package com.example.mse2android;

import android.content.Intent;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.graphics.Color;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    Button play,stop,change;
    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate( savedInstanceState );
        setContentView( R.layout.activity_main );
        play=findViewById( R.id.button );
        stop=findViewById( R.id.button1);
        change=findViewById( R.id.button2);
        play.setOnClickListener( new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startService( new Intent( getApplicationContext(),MyService.class ) );
            }
        } );
        stop.setOnClickListener( new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                stopService( new Intent( getApplicationContext(),MyService.class ) );
            }
        } );
        change.setOnClickListener( new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ConstraintLayout c=findViewById( R.id.cl );
                Random gen=new Random();
                c.setBackgroundColor( Color.rgb( gen.nextInt(),gen.nextInt(),gen.nextInt()));
            }
        } );
    }
}

