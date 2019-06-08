package com.ijbamboo.pattern.composite.example.tea;

import java.util.ListIterator;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����8:54:00
 */
public class OneTeaBag extends TeaBags { 
    public OneTeaBag(String nameIn) {
        this.setName(nameIn);
    }
    
    public int countTeaBags() {
        return 1;
    }
   
    public boolean add(TeaBags teaBagsToAdd) {
        return false;
    }
    public boolean remove(TeaBags teaBagsToRemove) {
        return false;
    }
    public ListIterator createListIterator() {
        return null;
    }
}