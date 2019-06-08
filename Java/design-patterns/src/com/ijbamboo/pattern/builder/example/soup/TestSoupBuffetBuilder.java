package com.ijbamboo.pattern.builder.example.soup;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午3:44:43
 */
public class TestSoupBuffetBuilder {

	public static SoupBuffet CreateSoupBuffet(SoupBuffetBuilder soupBuffetBuilder) {
		soupBuffetBuilder.buildSoupBuffet();

		soupBuffetBuilder.setSoupBuffetName();

		soupBuffetBuilder.buildChickenSoup();
		soupBuffetBuilder.buildClamChowder();
		soupBuffetBuilder.buildFishChowder();
		soupBuffetBuilder.buildMinnestrone();
		soupBuffetBuilder.buildPastaFazul();
		soupBuffetBuilder.buildTofuSoup();
		soupBuffetBuilder.buildVegetableSoup();

		return soupBuffetBuilder.getSoupBuffet();
	}     
		    
		   public static void main(String[] args) {
		       
		       SoupBuffet bostonSoupBuffet = 
		         CreateSoupBuffet(new BostonSoupBuffetBuilder());
		       System.out.println("At the " + 
		                           bostonSoupBuffet.getSoupBuffetName() + 
		                           bostonSoupBuffet.getTodaysSoups());


		       SoupBuffet honoluluSoupBuffet = 
		         CreateSoupBuffet(new HonoluluSoupBuffetBuilder());
		       System.out.println("At the " + 
		                           honoluluSoupBuffet.getSoupBuffetName() + 
		                           honoluluSoupBuffet.getTodaysSoups());
		   }
		}