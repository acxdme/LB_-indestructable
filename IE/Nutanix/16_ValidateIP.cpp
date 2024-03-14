// lc - 468

/**
 * @param {string} queryIP
 * @return {string}
 */
var validIPAddress = function (queryIP) {
    let segments = queryIP.split('.');
    if (segments.length == 0) {
        segments = queryIP.split(':');
    }

    if (segments.length == 0) {
        return "Neither";
    }

    if (segments.length == 4) { // validate ipv4
        segments.forEach((item) => {
            if (item.length > 0 && item[0] == '0') {
                return "Neither";
            }
            let val =  +item;
            if (Number.isNaN(val)) {
                return "Neither";
            }
            if (!(val >= 1 && val <= 255)) {
                return "Neither";
            }

        })
        return "IPv4";
    }
    else { // validate ipv6
        segments.forEach((item) => {
            if (item.length > 0 && item[0] == '0') {
                return "Neither";
            }
            if (!(item.length >= 1 && item.length <= 4)) {
                return "Neither";
            }
            item.forEach((char) => {
                if (!(char >= 'a' && char <= 'z') || !(char >= 'A' && char <= 'Z') || !(char >= '0' && char <= '9')) {
                    return "Neither";
                }
            })
        });

        return "IPv6";
    }


};
