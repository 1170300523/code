package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:47:31
 */
public class TestTitleVisitor {
	public static void main(String[] args) {
	       AbstractTitleInfo bladeRunner = 
	         new DvdInfo("Blade Runner", "Harrison Ford", '1');
	       AbstractTitleInfo electricSheep = 
	         new BookInfo("Do Androids Dream of Electric Sheep?", 
	                      "Phillip K. Dick");
	       AbstractTitleInfo sheepRaider = 
	         new GameInfo("Sheep Raider");
	       
	       TitleBlurbVisitor titleLongBlurbVisitor = 
	         new TitleLongBlurbVisitor();
	       
	       System.out.println("Long Blurbs:");     
	       bladeRunner.accept(titleLongBlurbVisitor);
	       System.out.println("Testing bladeRunner   " + 
	                           titleLongBlurbVisitor.getTitleBlurb());
	       electricSheep.accept(titleLongBlurbVisitor);
	       System.out.println("Testing electricSheep " + 
	                           titleLongBlurbVisitor.getTitleBlurb());
	       sheepRaider.accept(titleLongBlurbVisitor);
	       System.out.println("Testing sheepRaider   " + 
	                           titleLongBlurbVisitor.getTitleBlurb());
	       
	       TitleBlurbVisitor titleShortBlurbVisitor = 
	         new TitleShortBlurbVisitor();
	       
	       System.out.println("Short Blurbs:");     
	       bladeRunner.accept(titleShortBlurbVisitor);
	       System.out.println("Testing bladeRunner   " + 
	         titleShortBlurbVisitor.getTitleBlurb());
	       electricSheep.accept(titleShortBlurbVisitor);
	       System.out.println("Testing electricSheep " + 
	         titleShortBlurbVisitor.getTitleBlurb());
	       sheepRaider.accept(titleShortBlurbVisitor);
	       System.out.println("Testing sheepRaider   " + 
	         titleShortBlurbVisitor.getTitleBlurb());
	   }
	}      
