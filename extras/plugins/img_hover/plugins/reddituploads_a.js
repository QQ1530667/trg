var img_hover_plugins = img_hover_plugins || [];
img_hover_plugins.push({
	prepare_links:function(links) {
		for (var i = 0; i < links.length; ++i) {
			if (links[i].href.match(/^[A-Za-z0-9+.-]+:\/\/i\.reddituploads\.com\/([A-Fa-f0-9]{32})(?:$|[?#].*$)/i)) {
				links[i].addEventListener('mouseover', function() {
						img_hover.display_image(this, this.href)
					}, false);
			}
		}
	}
});
