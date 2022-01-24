QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/imagewidget.cpp \
    main.cpp \
    src/json.cpp \
    src/lib/base64.cpp \
    src/lib/cache/jsoncache.cpp \
    src/lib/crash/crashhandler.cpp \
    src/lib/crash/crashinfo.cpp \
    src/lib/developermode.cpp \
    src/lib/libhttpclient.cpp \
    src/lib/log.cpp \
    src/lib/log/datetime.cpp \
    src/lib/log/logmessage.cpp \
    src/lib/spotfiy/album.cpp \
    src/lib/spotfiy/api.cpp \
    src/lib/spotfiy/artist.cpp \
    src/lib/spotfiy/auth.cpp \
    src/lib/spotfiy/context.cpp \
    src/lib/spotfiy/device.cpp \
    src/lib/spotfiy/entity.cpp \
    src/lib/spotfiy/playback.cpp \
    src/lib/spotfiy/playlist.cpp \
    src/lib/spotfiy/playlistdetails.cpp \
    src/lib/spotfiy/savedalbum.cpp \
    src/lib/spotfiy/searchresults.cpp \
    src/lib/spotfiy/spotifyerror.cpp \
    src/lib/spotfiy/track.cpp \
    src/lib/spotfiy/trackinfo.cpp \
    src/lib/spotfiy/user.cpp \
    src/lib/strings.cpp \
    src/mainwindow.cpp \
    src/network.c \
    src/qt/httpclient.cpp \
    src/qt/qtpaths.cpp \
    src/settings.cpp \
    src/spotify/audiofeature.cpp \
    src/spotify/audiofeatures.cpp \
    src/spotify/spotify.cpp \
    src/spotifyapi/albums.cpp \
    src/spotifyapi/artists.cpp \
    src/spotifyapi/browse.cpp \
    src/spotifyapi/follow.cpp \
    src/spotifyapi/library.cpp \
    src/spotifyapi/personalization.cpp \
    src/spotifyapi/player.cpp \
    src/spotifyapi/playlists.cpp \
    src/spotifyapi/search.cpp \
    src/spotifyapi/tracks.cpp \
    src/spotifyapi/userprofile.cpp \
    src/test.cpp \

HEADERS += \
    include/lib/base64.h \
    include/lib/cache.h \
    include/lib/cache/jsoncache.h \
    include/lib/crash/crashhandler.h \
    include/lib/crash/crashinfo.h \
    include/lib/developermode.h \
    include/imagewidget.h \
    include/lib/format.h \
    include/lib/httpclient.h \
    include/lib/json.h \
    include/lib/log.h \
    include/lib/log/datetime.h \
    include/lib/log/logmessage.h \
    include/lib/log/logtype.h \
    include/lib/paths.h \
    include/lib/settings.h \
    include/lib/settings/account.h \
    include/lib/settings/general.h \
    include/lib/settings/qt.h \
    include/lib/settings/spotify.h \
    include/lib/spotify/album.h \
    include/lib/spotify/albumgroup.h \
    include/lib/spotify/api.h \
    include/lib/spotify/artist.h \
    include/lib/spotify/audiofeature.h \
    include/lib/spotify/audiofeatureenum.h \
    include/lib/spotify/audiofeatures.h \
    include/lib/spotify/audiokey.h \
    include/lib/spotify/audiomode.h \
    include/lib/spotify/audioquality.h \
    include/lib/spotify/auth.h \
    include/lib/spotify/callback.h \
    include/lib/spotify/context.h \
    include/lib/spotify/device.h \
    include/lib/spotify/entity.h \
    include/lib/spotify/error.h \
    include/lib/spotify/followtype.h \
    include/lib/spotify/playback.h \
    include/lib/spotify/playlist.h \
    include/lib/spotify/playlistdetails.h \
    include/lib/spotify/repeatstate.h \
    include/lib/spotify/savedalbum.h \
    include/lib/spotify/searchresults.h \
    include/lib/spotify/spotifycontext.h \
    include/lib/spotify/track.h \
    include/lib/spotify/trackinfo.h \
    include/lib/spotify/user.h \
    include/lib/strings.h \
    include/lib/util/treeutils.h \
    include/lib/vector.h \
    include/mainwindow.h \
    include/network.h \
    include/qt/httpclient.h \
    include/qt/qtpaths.h \
    include/spotify/current.h \
    include/spotify/spotify.h \
    thirdparty/json/include/nlohmann/adl_serializer.hpp \
    thirdparty/json/include/nlohmann/byte_container_with_subtype.hpp \
    thirdparty/json/include/nlohmann/detail/conversions/from_json.hpp \
    thirdparty/json/include/nlohmann/detail/conversions/to_chars.hpp \
    thirdparty/json/include/nlohmann/detail/conversions/to_json.hpp \
    thirdparty/json/include/nlohmann/detail/exceptions.hpp \
    thirdparty/json/include/nlohmann/detail/hash.hpp \
    thirdparty/json/include/nlohmann/detail/input/binary_reader.hpp \
    thirdparty/json/include/nlohmann/detail/input/input_adapters.hpp \
    thirdparty/json/include/nlohmann/detail/input/json_sax.hpp \
    thirdparty/json/include/nlohmann/detail/input/lexer.hpp \
    thirdparty/json/include/nlohmann/detail/input/parser.hpp \
    thirdparty/json/include/nlohmann/detail/input/position_t.hpp \
    thirdparty/json/include/nlohmann/detail/iterators/internal_iterator.hpp \
    thirdparty/json/include/nlohmann/detail/iterators/iter_impl.hpp \
    thirdparty/json/include/nlohmann/detail/iterators/iteration_proxy.hpp \
    thirdparty/json/include/nlohmann/detail/iterators/iterator_traits.hpp \
    thirdparty/json/include/nlohmann/detail/iterators/json_reverse_iterator.hpp \
    thirdparty/json/include/nlohmann/detail/iterators/primitive_iterator.hpp \
    thirdparty/json/include/nlohmann/detail/json_pointer.hpp \
    thirdparty/json/include/nlohmann/detail/json_ref.hpp \
    thirdparty/json/include/nlohmann/detail/macro_scope.hpp \
    thirdparty/json/include/nlohmann/detail/macro_unscope.hpp \
    thirdparty/json/include/nlohmann/detail/meta/call_std/begin.hpp \
    thirdparty/json/include/nlohmann/detail/meta/call_std/end.hpp \
    thirdparty/json/include/nlohmann/detail/meta/cpp_future.hpp \
    thirdparty/json/include/nlohmann/detail/meta/detected.hpp \
    thirdparty/json/include/nlohmann/detail/meta/identity_tag.hpp \
    thirdparty/json/include/nlohmann/detail/meta/is_sax.hpp \
    thirdparty/json/include/nlohmann/detail/meta/type_traits.hpp \
    thirdparty/json/include/nlohmann/detail/meta/void_t.hpp \
    thirdparty/json/include/nlohmann/detail/output/binary_writer.hpp \
    thirdparty/json/include/nlohmann/detail/output/output_adapters.hpp \
    thirdparty/json/include/nlohmann/detail/output/serializer.hpp \
    thirdparty/json/include/nlohmann/detail/string_escape.hpp \
    thirdparty/json/include/nlohmann/detail/value_t.hpp \
    thirdparty/json/include/nlohmann/json.hpp \
    thirdparty/json/include/nlohmann/json_fwd.hpp \
    thirdparty/json/include/nlohmann/ordered_map.hpp \
    thirdparty/json/include/nlohmann/thirdparty/hedley/hedley.hpp \
    thirdparty/json/include/nlohmann/thirdparty/hedley/hedley_undef.hpp \
    thirdparty/json/single_include/nlohmann/json.hpp \

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    DAC_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

VERSION = 1.2.3.4

DEFINES += APP_VERSION=\\\"$$VERSION\\\"


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/spotifyapi/readme.md

