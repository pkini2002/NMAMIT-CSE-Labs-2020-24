- Once you create the necessary layout files and .java files the next step is to create a menu
- Thos can be done by right clicking on res folder -> New -> Android Resource file
- Resource Type : Menu
- File Name : Anyname (In my case I have given m1 as the file name)
- Then you can drag and drop the menu item from the palette
- Make sure to change the layout filenames in MainActivity1.java and MainActivity2.java file
- Finally add these lines in AndroidManifest.xml file after </activity> and above </application>

`<activity android:name=".MainActivity1"></activity>`
`<activity android:name=".MainActivity2"></activity>`
