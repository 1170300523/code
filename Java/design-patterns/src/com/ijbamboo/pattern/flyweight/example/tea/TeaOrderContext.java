package com.ijbamboo.pattern.flyweight.example.tea;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:05:32
 */
public class TeaOrderContext {
	int tableNumber; 
	   
	   TeaOrderContext(int tableNumber) {
	       this.tableNumber = tableNumber;
	   }
	   
	   public int getTable() {
	       return this.tableNumber;
	   }
	}