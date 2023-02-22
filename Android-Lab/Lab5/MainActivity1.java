// Design a phone call application that takes a phone number from the user.

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
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    EditText phone;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ActivityCompat.requestPermissions(this,new
                String[]{Manifest.permission.CALL_PHONE},1);
        phone=findViewById(R.id.phoneno);
        btn=findViewById(R.id.button2);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String number=phone.getText().toString();
                Intent callintent=new Intent(Intent.ACTION_CALL);
                callintent.setData(Uri.parse("tel:"+number));
                try {
                    startActivity(callintent);
                }catch (Exception e){
                    Log.d("error",e.getMessage());
                    Toast.makeText(getApplicationContext(),
                            "Call permission denied",Toast.LENGTH_SHORT).show();
                }

            }
        });
    }
}

// Add this line in Manifest file to give permission to make a call
<uses-permission android:name="android.permission.CALL_PHONE" />
