package com.ijbamboo.pattern.State.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:38:14
 */
public class TestState {

	 public static void main(String[] args) 
	   {
	       DvdStateContext stateContext = new DvdStateContext();
	       stateContext.showName(
	         "Sponge Bob Squarepants - "+
	           "Nautical Nonsense and Sponge Buddies");
	       stateContext.showName(
	         "Jay and Silent Bob Strike Back");  
	       stateContext.showName(
	         "Buffy The Vampire Slayer Season 2");
	       stateContext.showName(
	         "The Sopranos Season 2");
	   }
	} 
