package com.ijbamboo.pattern.facade.example.cup;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:02:56
 */
public class TestFacade {

		   public static void main(String[] args) {
		       FacadeCuppaMaker cuppaMaker = new FacadeCuppaMaker();
		       FacadeTeaCup teaCup = cuppaMaker.makeACuppa();
		       System.out.println(teaCup);
		   }
		}
