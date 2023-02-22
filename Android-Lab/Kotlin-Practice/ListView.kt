// In Strings.xml type this:

<resources>
    <string name="app_name">MessageDisplay</string>

    <string-array name="countries">
        <item>India</item>
        <item>England</item>
        <item>Netherlands</item>
        <item>Belgium</item>
        <item>Germany</item>
        <item>America</item>
        <item>Russia</item>
        <item>Greece</item>
        <item>Mexico</item>
    </string-array>
</resources>
  
 // Logic in MainActivity.kt file

package com.example.messagedisplay

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.PersistableBundle
import android.view.View
import android.widget.*
import androidx.constraintlayout.widget.ConstraintLayout


class MainActivity : AppCompatActivity() {
    lateinit var listView:ListView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        listView=findViewById(R.id.listview)
        var countryList=resources.getStringArray(R.array.countries)
        var arrayAdapter=ArrayAdapter(this,android.R.layout.simple_list_item_1,countryList)
        listView.adapter=arrayAdapter

        listView.setOnItemClickListener{
            parent,view,position,id ->
            val countryName:String = parent.getItemAtPosition(position).toString()
            Toast.makeText(applicationContext,
                "You selected the "+countryName,
                Toast.LENGTH_LONG).show()
        }
    }
}
