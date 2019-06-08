package com.ijbamboo.pattern.adapter.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:45:09
 */
public class TestTeaBagAdaptation {
	 public static void main(String[] args) {
	       TeaCup teaCup = new TeaCup();


	       System.out.println("Steeping tea bag");
	       TeaBag teaBag = new TeaBag();       
	       teaCup.steepTeaBag(teaBag);


	       System.out.println("Steeping loose leaf tea");
	       LooseLeafTea looseLeafTea = new LooseLeafTea();
	       TeaBall teaBall = new TeaBall(looseLeafTea);
	       teaCup.steepTeaBag(teaBall);
	   }
	} 