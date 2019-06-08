package com.ijbamboo.pattern.bridge.example.soda;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����8:50:45
 */
public class SodaImpSingleton {  
    private static SodaImp sodaImp;
   
    public SodaImpSingleton(SodaImp sodaImpIn) {
        this.sodaImp = sodaImpIn;
    }
    
    public static SodaImp getTheSodaImp() {
        return sodaImp;
    }
}