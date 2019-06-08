package com.ijbamboo.pattern.flyweight.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:05:32
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