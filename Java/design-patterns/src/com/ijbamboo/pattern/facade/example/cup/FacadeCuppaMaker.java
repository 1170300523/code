package com.ijbamboo.pattern.facade.example.cup;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:00:50
 */
public class FacadeCuppaMaker {

	boolean teaBagIsSteeped; 
    
	   public FacadeCuppaMaker() {
	       System.out.println(
	         "FacadeCuppaMaker ready to make you a cuppa!");
	   }
	   
	   public FacadeTeaCup makeACuppa() {
	       FacadeTeaCup cup = new FacadeTeaCup();
	       FacadeTeaBag teaBag = new FacadeTeaBag();
	       FacadeWater water = new FacadeWater();
	       cup.addFacadeTeaBag(teaBag);
	       water.boilFacadeWater();
	       cup.addFacadeWater(water);
	       cup.steepTeaBag();
	       return cup;
	   }
	}