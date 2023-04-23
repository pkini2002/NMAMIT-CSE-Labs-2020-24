package com.example.mse2android;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    ProgressBar pb;
    Button btn;
    TextView t;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        pb=findViewById(R.id.progressBar2);
        btn=findViewById(R.id.button);
        t=findViewById(R.id.textView);
        btn.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        T t1=new T();
        t1.execute("10");
    }

    class T extends AsyncTask<String,Integer,String>{
        @Override
        protected String doInBackground(String... strings) {
            int max=Integer.parseInt(strings[0]);
            int i=0;
            while(i<max){
                try{
                    Thread.sleep(1000);
                }catch(InterruptedException e){
                    e.printStackTrace();
                }
                i++;
                publishProgress(i);
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(Integer... values) {
            pb.setProgress(values[0]);
            t.setText(values[0].toString());
            super.onProgressUpdate(values);
        }
    }
}

