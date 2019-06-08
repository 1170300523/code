package com.ijbamboo.pattern.command.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:17:30
 */
public class DvdCommandNameStarsOn extends CommandAbstract {
	   private DvdName dvdName;  
	    
	   public DvdCommandNameStarsOn(DvdName dvdNameIn) {
	       this.dvdName = dvdNameIn;
	   }    
	   public void execute() {
	       this.dvdName.setNameStarsOn();
	   } 
	}