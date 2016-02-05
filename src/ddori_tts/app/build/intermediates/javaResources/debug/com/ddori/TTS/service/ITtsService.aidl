// ITtsService.aidl
package com.ddori.TTS.service;

// Declare any non-default types here with import statements


interface ITtsService {
    /**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
     void SetTts(String ttstext);
 //   void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat,double aDouble, String aString);
}
