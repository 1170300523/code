package com.ijbamboo.pattern.command.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:17:30
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