package com.ijbamboo.pattern.abstractfactory.example.soup;

import java.util.Calendar;

import com.ijbamboo.pattern.soup.Soup;

/**
 * @author ����
 * @Description
 * @version 1.0 2018��2��3�� ����1:44:26
 */
public class TestAbstractSoupFactory {
	
	public static Soup MakeSoupOfTheDay(AbstractSoupFactory concreteSoupFactory) {
		Calendar todayCalendar = Calendar.getInstance();
		// int dayOfWeek = todayCalendar.get(Calendar.DAY_OF_WEEK);

		int dayOfWeek = Calendar.TUESDAY;

		if (dayOfWeek == Calendar.MONDAY) {
			return concreteSoupFactory.makeChickenSoup();
		} else if (dayOfWeek == Calendar.TUESDAY) {
			return concreteSoupFactory.makeClamChowder();
		} else if (dayOfWeek == Calendar.WEDNESDAY) {
			return concreteSoupFactory.makeFishChowder();
		} else if (dayOfWeek == Calendar.THURSDAY) {
			return concreteSoupFactory.makeMinnestrone();
		} else if (dayOfWeek == Calendar.FRIDAY) {
			return concreteSoupFactory.makePastaFazul();
		} else if (dayOfWeek == Calendar.SATURDAY) {
			return concreteSoupFactory.makeTofuSoup();
		} else {
			return concreteSoupFactory.makeVegetableSoup();
		}
	}

	public static void main(String[] args) {
		AbstractSoupFactory concreteSoupFactory = new BostonConcreteSoupFactory();
		Soup soupOfTheDay = MakeSoupOfTheDay(concreteSoupFactory);
		System.out.println("The Soup of the day "
				+ concreteSoupFactory.getFactoryLocation() + " is "
				+ soupOfTheDay.getSoupName());

		concreteSoupFactory = new HonoluluConcreteSoupFactory();
		soupOfTheDay = MakeSoupOfTheDay(concreteSoupFactory);
		System.out.println("The Soup of the day "
				+ concreteSoupFactory.getFactoryLocation() + " is "
				+ soupOfTheDay.getSoupName());
	}
}
