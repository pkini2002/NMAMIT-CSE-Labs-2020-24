package com.example.androidlifecycle;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;


public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    protected void onStart() {
        super.onStart();
        Log.d("Lifecycle","onStart created");
    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.d("Lifecycle","onResume created");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.d("Lifecycle","onPause created");
    }

    @Override
    protected void onStop() {
        super.onStop();
        Log.d("Lifecycle","onStop created");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Log.d("Lifecycle","onRestart created");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d("Lifecycle","onDestroy created");
    }
}
