package com.ijbamboo.pattern.command.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:17:50
 */
public class DvdCommandNameStarsOff extends CommandAbstract {  
	   private DvdName dvdName;  
	    
	   public DvdCommandNameStarsOff(DvdName dvdNameIn) {
	       this.dvdName = dvdNameIn;
	   }    
	   public void execute() {
	       this.dvdName.setNameStarsOff();
	   } 
	}