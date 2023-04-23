package com.example.mse2android;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
public class MainActivity2 extends AppCompatActivity {
    WebView page;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        page = findViewById(R.id.web);
        page.setWebViewClient(new WebViewClient());
        Intent i = getIntent();
        String url = i.getStringExtra("load");
        if (url.equals("defaultpage")) {
            page.loadUrl("https://www.google.com");
        } else {
            page.loadUrl(url);
        }
    }
}
