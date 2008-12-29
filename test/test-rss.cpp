/* test driver for rsspp */

#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/auto_unit_test.hpp>

#include <rsspp.h>


BOOST_AUTO_TEST_CASE(TestParseSimpleRSS_0_91) {
	rsspp::parser p;

	rsspp::feed f = p.parse_file("data/rss091_1.xml");

	BOOST_CHECK_EQUAL(f.rss_version, rsspp::RSS_0_91);
	BOOST_CHECK_EQUAL(f.title, "Example Channel");
	BOOST_CHECK_EQUAL(f.description, "an example feed");
	BOOST_CHECK_EQUAL(f.link, "http://example.com/");
	BOOST_CHECK_EQUAL(f.language, "en");

	BOOST_CHECK_EQUAL(f.items.size(), 1u);
	BOOST_CHECK_EQUAL(f.items[0].title, "1 < 2");
	BOOST_CHECK_EQUAL(f.items[0].link, "http://example.com/1_less_than_2.html");
	BOOST_CHECK_EQUAL(f.items[0].description, "1 < 2, 3 < 4.\nIn HTML, <b> starts a bold phrase\nand you start a link with <a href=\n");
	BOOST_CHECK_EQUAL(f.items[0].author, "");
	BOOST_CHECK_EQUAL(f.items[0].guid, "");
}

BOOST_AUTO_TEST_CASE(TestParseSimpleRSS_0_92) {
	rsspp::parser p;

	rsspp::feed f = p.parse_file("data/rss092_1.xml");

	BOOST_CHECK_EQUAL(f.rss_version, rsspp::RSS_0_92);
	BOOST_CHECK_EQUAL(f.title, "Example Channel");
	BOOST_CHECK_EQUAL(f.description, "an example feed");
	BOOST_CHECK_EQUAL(f.link, "http://example.com/");
	BOOST_CHECK_EQUAL(f.language, "en");

	BOOST_CHECK_EQUAL(f.items.size(), 2u);

	BOOST_CHECK_EQUAL(f.items[0].title, "1 < 2");
	BOOST_CHECK_EQUAL(f.items[0].link, "http://example.com/1_less_than_2.html");
	BOOST_CHECK_EQUAL(f.items[0].description, "1 < 2, 3 < 4.\nIn HTML, <b> starts a bold phrase\nand you start a link with <a href=\n");
	BOOST_CHECK_EQUAL(f.items[0].author, "");
	BOOST_CHECK_EQUAL(f.items[0].guid, "");

	BOOST_CHECK_EQUAL(f.items[1].title, "A second item");
	BOOST_CHECK_EQUAL(f.items[1].link, "http://example.com/a_second_item.html");
	BOOST_CHECK_EQUAL(f.items[1].description, "no description");
	BOOST_CHECK_EQUAL(f.items[1].author, "");
	BOOST_CHECK_EQUAL(f.items[1].guid, "");
}

BOOST_AUTO_TEST_CASE(TestParseSimpleRSS_2_0) {
	rsspp::parser p;

	rsspp::feed f = p.parse_file("data/rss20_1.xml");

	BOOST_CHECK_EQUAL(f.title, "my weblog");
	BOOST_CHECK_EQUAL(f.link, "http://example.com/blog/");
	BOOST_CHECK_EQUAL(f.description, "my description");

	BOOST_CHECK_EQUAL(f.items.size(), 1u);

	BOOST_CHECK_EQUAL(f.items[0].title, "this is an item");
	BOOST_CHECK_EQUAL(f.items[0].link, "http://example.com/blog/this_is_an_item.html");
	BOOST_CHECK_EQUAL(f.items[0].author, "Andreas Krennmair");
	BOOST_CHECK_EQUAL(f.items[0].author_email, "blog@synflood.at");
	BOOST_CHECK_EQUAL(f.items[0].content_encoded, "oh well, this is the content.");
	BOOST_CHECK_EQUAL(f.items[0].pubDate, "Fri, 12 Dec 2008 02:36:10 +0100");
	BOOST_CHECK_EQUAL(f.items[0].guid, "http://example.com/blog/this_is_an_item.html");
	BOOST_CHECK_EQUAL(f.items[0].guid_isPermaLink, false);
}