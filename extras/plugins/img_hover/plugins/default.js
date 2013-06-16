var img_hover_plugins = img_hover_plugins || [];
img_hover_plugins.push({
	name:'default',
	prepare_links:function(links) {
		for (var i = 0; i < links.length; ++i) {
			if (links[i].href.match(/.*\.(?:jpg|jpeg|gif|png|svg|webp|bmp|ico|xbm)[\?\#]?.*$/i)) {
				links[i].addEventListener('mouseover', function() {
						img_hover.display_image(this, this.href)
					}, false);
			}
		}
	}
});
