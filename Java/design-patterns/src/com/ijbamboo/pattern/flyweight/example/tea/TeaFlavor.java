package com.ijbamboo.pattern.flyweight.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:05:00
 */
public class TeaFlavor  extends TeaOrder {  
    String teaFlavor; 
   
    TeaFlavor(String teaFlavor) {
        this.teaFlavor = teaFlavor;
    }
   
    public String getFlavor() {
        return this.teaFlavor;
    }
   
    public void serveTea(TeaOrderContext teaOrderContext) {
        System.out.println("Serving tea flavor " + 
                             teaFlavor + 
                           " to table number " + 
                             teaOrderContext.getTable());
    }
}