/*
 * Red Hat OpenShift Mobile
 * 2016
 */
package com.example.jniexperiment;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;


public class JniExperiment extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        TextView  tv = new TextView(this);
        tv.setText( helloString() );
        setContentView(tv);
    }

    public native String helloString();

    static {
        System.loadLibrary("jni-experiment");
    }
}
