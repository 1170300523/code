package com.ijbamboo.pattern.bridge.example.soda;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:50:45
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