package com.ijbamboo.pattern.adapter.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:43:31
 */
public class TeaBall extends TeaBag {  
	   LooseLeafTea looseLeafTea;
	   
	   public TeaBall(LooseLeafTea looseLeafTeaIn) {
	       looseLeafTea = looseLeafTeaIn;
	       teaBagIsSteeped = looseLeafTea.teaIsSteeped;
	   }
	    
	   public void steepTeaInCup() {
	       looseLeafTea.steepTea();
	       teaBagIsSteeped = true;
	   }
	}