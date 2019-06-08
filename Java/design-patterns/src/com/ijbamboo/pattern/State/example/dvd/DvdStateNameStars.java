package com.ijbamboo.pattern.State.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:37:55
 */
public class DvdStateNameStars implements DvdStateName {  
    int starCount;
    
    public DvdStateNameStars() {
        starCount = 0;
    }
    
    public void showName(DvdStateContext dvdStateContext, 
                         String nameIn) {
         System.out.println(nameIn.replace(' ','*'));
         // show stars twice, switch to exclamation point
         if (++starCount > 1) {
             dvdStateContext.setDvdStateName(
               new DvdStateNameExclaim());
         }       
    }  
}
