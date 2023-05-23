package com.example.db_app;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import android.Manifest;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    EditText t1,t2,t3,t4;
    Button btn1,btn2;
    SQLiteDatabase db=null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        t1=findViewById(R.id.editTextTextPersonName);
        t2=findViewById(R.id.editTextTextPersonName2);
        t3=findViewById(R.id.editTextTextPersonName3);
        t4=findViewById(R.id.editTextTextPersonName4);

        btn1=findViewById(R.id.button);
        btn2=findViewById(R.id.button2);

        ActivityCompat.requestPermissions( this,new String[]{Manifest.permission.CALL_PHONE},1 );
        btn1.setOnClickListener(this);
        btn2.setOnClickListener(this);
    }

    @SuppressLint("Range")
    @Override
    public void onClick(View view) {
        String name, usn,ph;
        usn = t1.getText().toString();
        name = t2.getText().toString();
        ph = t3.getText().toString();
        try {
            db = this.openOrCreateDatabase( "stud01", MODE_PRIVATE, null );
            db.execSQL("create table if not exists test(usn varchar(20),name varchar(20),phone varchar(20));");
            if(view.getId()==btn1.getId())
            {
                db.execSQL( "insert into test values('"+usn+"','"+name+"','"+ph+"');" );
                Toast.makeText(getApplicationContext(),"Row inserted succesfully",Toast.LENGTH_SHORT ).show();
            }
            if(view.getId()==btn2.getId())
            {
                Cursor c=db.rawQuery( "select * from test where usn='"+t4.getText().toString()+"';",null );
                if(c.getCount()!=1)
                {
                    Toast.makeText( getApplicationContext(),"invalid",Toast.LENGTH_SHORT ).show();
                }
                else
                {
                    c.moveToNext();
                    ph=c.getString( c.getColumnIndex( "phone" ) ) ;
                    Intent i=new Intent( Intent.ACTION_CALL );
                    i.setData( Uri.parse("tel:"+ph) );
                    startActivity( i );
                }
            }
        }
        catch (SQLiteException e)
        {
            Toast.makeText( getApplicationContext(),"Error",Toast.LENGTH_SHORT ).show();

        }
        finally {
            if(db!=null)
                db.close();
        }
    }
}
