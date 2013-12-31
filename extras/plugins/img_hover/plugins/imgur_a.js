var img_hover_plugins = img_hover_plugins || [];
img_hover_plugins.push({
	name:'imgur_a',
	prepare_links:function(links) {
		for (var i = 0; i < links.length; ++i) {
			var matches = links[i].href.match(/.*:\/\/(?:www\.|i\.|m\.)?imgur\.com\/([a-zA-Z0-9]{5,7})(?:$|[\?\#].*$)/);
			if (matches && matches[1]) {
				image_url = 'http://i.imgur.com/' + matches[1] + '.jpg';
				links[i].addEventListener('mouseover', {
						element:links[i],
						href:image_url,
						handleEvent:function(event) {
							img_hover.display_image(this.element, this.href);
						}
					}, false);
			}
		}
	}
});
