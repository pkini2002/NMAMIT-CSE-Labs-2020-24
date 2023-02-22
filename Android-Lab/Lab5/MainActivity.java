// Design an application that sends SMS using SmsManger App/Built in SMS app.

package com.example.messageapp;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import android.Manifest;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    EditText email,msg;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ActivityCompat.requestPermissions(this,new String[]{Manifest.permission.SEND_SMS},1);

        email=findViewById(R.id.email);
        msg=findViewById(R.id.message);
        btn=findViewById(R.id.button);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String value = email.getText().toString();
                Intent i = new Intent(Intent.ACTION_VIEW, Uri.parse("sms:" + value));
                i.putExtra("sms_body", msg.getText().toString());
                try {
                    startActivity(i);
                } catch (android.content.ActivityNotFoundException ex) {
                    Toast.makeText(MainActivity.this, "Permission denied",
                            Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}

// Make sure to add permission in AndroidManifest.xml

<uses-permission android:name="android.permission.SEND_SMS" />
