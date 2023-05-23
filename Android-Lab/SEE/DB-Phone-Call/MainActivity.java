package com.example.see;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.core.app.ActivityCompat;

import android.annotation.SuppressLint;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.drawable.BitmapDrawable;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.BatteryManager;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import android.Manifest;

import java.util.Random;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    EditText t1,t2,t3,t4;
    Button insert,call;

    SQLiteDatabase db=null;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        t1=findViewById(R.id.editTextTextPersonName);
        t2=findViewById(R.id.editTextTextPersonName2);
        t3=findViewById(R.id.editTextTextPersonName4);
        t4=findViewById(R.id.editTextTextPersonName3);
        ActivityCompat.requestPermissions( this,new String[]{Manifest.permission.CALL_PHONE},1 );
        insert=findViewById(R.id.button8);
        call=findViewById(R.id.button10);
        insert.setOnClickListener(this);
        call.setOnClickListener(this);
    }

    @SuppressLint("range")
    @Override
    public void onClick(View view) {
        String name,usn,phone;
        name=t1.getText().toString();
        usn=t2.getText().toString();
        phone=t3.getText().toString();

        try{
            db=this.openOrCreateDatabase("test",MODE_PRIVATE,null);
            db.execSQL("create table if not exists rsa(name varchar(20),usn varchar(15),phone varchar(15));");

            if(view.getId()==insert.getId()){
                db.execSQL("insert into rsa values('"+name+"','"+usn+"','"+phone+"')");
                Toast.makeText(this, "Row inserted", Toast.LENGTH_SHORT).show();
            }

            if(view.getId()==call.getId()){
                Cursor c=db.rawQuery("select * from rsa where usn='"+t4.getText().toString()+"';",null);
                if(c.getCount() != 1){
                    Toast.makeText(this, "Invalid", Toast.LENGTH_SHORT).show();
                }
                else{
                    c.moveToNext();
                    phone=c.getString(c.getColumnIndex("phone"));
                    Intent i=new Intent(Intent.ACTION_CALL);
                    i.setData(Uri.parse("tel:"+phone));
                    startActivity(i);
                }
            }
        }catch(SQLException sqlException){
            Toast.makeText(this, "Could not open or create db", Toast.LENGTH_SHORT).show();
        }
        finally{
            if(db!=null){
                db.close();
            }
        }
    }
}

// In Manifest file,   <uses-permission android:name="android.permission.CALL_PHONE" />
