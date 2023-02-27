package com.example.messageapp;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import android.Manifest;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    RadioButton call,sms,website;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ActivityCompat.requestPermissions(this,new
                String[]{Manifest.permission.CALL_PHONE},1);
        call=findViewById(R.id.call);
        sms=findViewById(R.id.sms);
        website=findViewById(R.id.website);

        btn=findViewById(R.id.button);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(!(call.isChecked() || sms.isChecked() || website.isChecked())){
                    Toast.makeText(MainActivity.this,"Select One",Toast.LENGTH_SHORT).show();
                }
                else{
                    if(call.isChecked()){
                        Intent i=new Intent(Intent.ACTION_CALL);
                        String number="7624914650";
                        i.setData(Uri.parse("tel:"+number));
                        startActivity(i);
                    }
                    else if(sms.isChecked()){
                        Intent i=new Intent(Intent.ACTION_VIEW);
                        i.setData(Uri.parse("sms:7624914650"));
                        i.putExtra("sms_body","Hello World");
                        startActivity(i);
                    }
                    else if(website.isChecked()){
                        Intent i=new Intent(Intent.ACTION_VIEW,Uri.parse("https://www.w3schools.com/"));
                        startActivity(i);
                    }
                }
            }
        });
    }
}
