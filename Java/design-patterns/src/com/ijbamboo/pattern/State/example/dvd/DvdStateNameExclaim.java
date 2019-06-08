package com.ijbamboo.pattern.State.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:37:36
 */
public class DvdStateNameExclaim  implements DvdStateName {  
    public DvdStateNameExclaim() {}
    
    public void showName(DvdStateContext dvdStateContext, 
                         String nameIn) {
         System.out.println(nameIn.replace(' ','!'));
         //show exclaim only once, switch back to stars
         dvdStateContext.setDvdStateName(new DvdStateNameStars());
    }  
}
