package com.ijbamboo.pattern.facade.example.cup;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:02:56
 */
public class TestFacade {

		   public static void main(String[] args) {
		       FacadeCuppaMaker cuppaMaker = new FacadeCuppaMaker();
		       FacadeTeaCup teaCup = cuppaMaker.makeACuppa();
		       System.out.println(teaCup);
		   }
		}
