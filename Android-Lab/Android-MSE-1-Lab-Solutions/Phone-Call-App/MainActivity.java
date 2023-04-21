package com.example.lab_programs;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.core.app.ActivityCompat;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import android.Manifest;

public class MainActivity extends AppCompatActivity {
    EditText phone;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ActivityCompat.requestPermissions(this,new String[]{Manifest.permission.CALL_PHONE},1);

        phone=findViewById(R.id.phone);
        btn=findViewById(R.id.button2);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String ph=phone.getText().toString();
                Intent callintent=new Intent(Intent.ACTION_CALL);
                callintent.setData(Uri.parse("tel:"+ph));
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


/* Note to use this line: ActivityCompat.requestPermissions(this,new String[]{Manifest.permission.CALL_PHONE},1);
   you need to import android.Manifest in MainActivity.java
   
   Add the below permission in AndroidManifest.xml
     <uses-permission android:name="android.permission.CALL_PHONE" />
     
*/
