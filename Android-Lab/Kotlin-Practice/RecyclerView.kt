// MainActivity.kt

package com.example.messagedisplay

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.PersistableBundle
import android.view.View
import android.widget.*
import androidx.constraintlayout.widget.ConstraintLayout
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView


class MainActivity : AppCompatActivity() {
    lateinit var recyclerView : RecyclerView
    var countryNameList = ArrayList<String>()
    var detailsList=ArrayList<String>()
    var imageList=ArrayList<Int>()

    lateinit var adapter: CountriesAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        recyclerView=findViewById(R.id.recycle)
        recyclerView.layoutManager=LinearLayoutManager(this@MainActivity)

        countryNameList.add("India")
        countryNameList.add("Australia")
        countryNameList.add("USA")

        detailsList.add("This is the flag of India")
        detailsList.add("This is the flag of Australia")
        detailsList.add("This is the flag of USA")

        imageList.add(R.drawable.indiaflag)
        imageList.add(R.drawable.australiaflag)
        imageList.add(R.drawable.americaflag)

        adapter=CountriesAdapter(countryNameList,detailsList,imageList,this@MainActivity)
        recyclerView.adapter=adapter
    }
}

// CountriesAdapter.kt

package com.example.messagedisplay

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.Toast
import androidx.cardview.widget.CardView
import androidx.recyclerview.widget.RecyclerView
import de.hdodenhof.circleimageview.CircleImageView

class CountriesAdapter(
    var countryNameList: ArrayList<String>,
    var detailsList: ArrayList<String>,
    var imageList: ArrayList<Int>,
    var context: Context
):RecyclerView.Adapter<CountriesAdapter.CountryViewHolder>()
{
    class CountryViewHolder(itemView:View):RecyclerView.ViewHolder(itemView){
            var textViewCountryName:TextView = itemView.findViewById(R.id.textView)
            var textViewDetails:TextView = itemView.findViewById(R.id.textView2)
            var imageView:CircleImageView=itemView.findViewById(R.id.imageView)
            var cardView:CardView=itemView.findViewById(R.id.cardview)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): CountryViewHolder {
        val view:View=LayoutInflater.from(parent.context).inflate(
            R.layout.card_design,parent,false
        )
        return CountryViewHolder(view)
    }

    override fun onBindViewHolder(holder: CountryViewHolder, position: Int) {
          holder.textViewCountryName.text=countryNameList.get(position)
          holder.textViewDetails.text=detailsList.get(position)
          holder.imageView.setImageResource(imageList.get(position))

          holder.cardView.setOnClickListener{
              Toast.makeText(context,"You selected the ${countryNameList.get(position)}",
              Toast.LENGTH_LONG).show()
          }
    }

    override fun getItemCount(): Int {
          return countryNameList.size
    }
}

// card_design.xml

<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <androidx.cardview.widget.CardView
        android:id="@+id/cardview"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_margin="7dp"
        app:cardBackgroundColor="#FFEB3B"
        app:cardCornerRadius="7dp"
        app:cardElevation="7dp"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent">

        <androidx.constraintlayout.widget.ConstraintLayout
            android:layout_width="match_parent"
            android:layout_height="75dp">

            <de.hdodenhof.circleimageview.CircleImageView
                android:id="@+id/imageView"
                android:layout_width="60dp"
                android:layout_height="60dp"
                android:layout_marginStart="5dp"
                android:src="@drawable/indiaflag"
                app:civ_border_color="#FF000000"
                app:civ_border_width="2dp"
                app:layout_constraintBottom_toBottomOf="parent"
                app:layout_constraintStart_toStartOf="parent"
                app:layout_constraintTop_toTopOf="parent" />

            <TextView
                android:id="@+id/textView"
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:layout_marginStart="20dp"
                android:text="TextView"
                android:textColor="#000"
                android:textSize="24sp"
                app:layout_constraintBottom_toTopOf="@+id/textView2"
                app:layout_constraintStart_toEndOf="@+id/imageView"
                app:layout_constraintTop_toTopOf="parent" />

            <TextView
                android:id="@+id/textView2"
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:layout_marginStart="20dp"
                android:text="TextView"
                android:textSize="16sp"
                app:layout_constraintBottom_toBottomOf="parent"
                app:layout_constraintStart_toEndOf="@+id/imageView"
                app:layout_constraintTop_toBottomOf="@+id/textView" />

        </androidx.constraintlayout.widget.ConstraintLayout>
    </androidx.cardview.widget.CardView>
</androidx.constraintlayout.widget.ConstraintLayout>
  
// activity_main.xml
  
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/constlayout"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <androidx.recyclerview.widget.RecyclerView
        android:id="@+id/recycle"
        android:layout_width="409dp"
        android:layout_height="0dp"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        tools:listitem="@layout/card_design" />
</androidx.constraintlayout.widget.ConstraintLayout>
