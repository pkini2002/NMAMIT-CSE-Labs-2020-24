// Kotlin Program for displaying Toast Message, SnackBar Message and Dialog Message

package com.example.messagedisplay

import android.content.DialogInterface
import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Message
import android.os.PersistableBundle
import android.view.View
import android.widget.Button
import android.widget.FrameLayout
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import androidx.constraintlayout.widget.ConstraintLayout
import com.google.android.material.snackbar.Snackbar

class MainActivity : AppCompatActivity() {
    lateinit var showToast:Button
    lateinit var showSnackbar: Button
    lateinit var myLayout: ConstraintLayout
    lateinit var showDialogMessage: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        showToast=findViewById(R.id.button)
        showSnackbar=findViewById(R.id.button2)
        myLayout=findViewById(R.id.constlayout)
        showDialogMessage=findViewById(R.id.button3)

        showToast.setOnClickListener{
            Toast.makeText(applicationContext,"This is a toast message",Toast.LENGTH_LONG).show()
        }

        showSnackbar.setOnClickListener {
            Snackbar.make(myLayout,"This is a Snackbar message",
                Snackbar.LENGTH_INDEFINITE).setAction("Close",
                View.OnClickListener {

               }).show()
        }

        showDialogMessage.setOnClickListener {
              showAlertDialog()
        }
    }

    fun showAlertDialog(){
           var alertDialog=AlertDialog.Builder(this@MainActivity)
           alertDialog.setTitle("Change")
               .setMessage("Do you want to change the text of the button?")
               .setIcon(R.drawable.warning)
               .setCancelable(false)
               .setNegativeButton("No", DialogInterface.OnClickListener {
                       dialogInterface, which ->
                       dialogInterface.cancel()
               })
               .setPositiveButton("Yes", DialogInterface.OnClickListener {
                       dialogInterface, which ->
                       showDialogMessage.text="Alert Dialog"
               })
        alertDialog.create().show()
    }
}
