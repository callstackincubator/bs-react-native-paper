[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Text";

let make =
    (
      ~selectable: bool=false,
      ~acessible: bool=false,
      ~elipsizeMode: option(string)=?,
      ~nativeID: option(string)=?,
      ~numberOfLines: option(int)=?,
      ~pressRetentionOffset: option(Js.t({..}))=?,
      ~allowFontScaling: bool=false,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onLayout: option(unit => unit)=?,
      ~onLongPress: option(unit => unit)=?,
      ~onPress: option(unit => unit)=?,
      ~testID: option(string)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.{
        "selectable": selectable,
        "acessible": acessible,
        "elipsizeMode": fromOption(elipsizeMode),
        "nativeID": fromOption(nativeID),
        "numberOfLines": fromOption(numberOfLines),
        "pressRetentionOffset": fromOption(pressRetentionOffset),
        "allowFontScaling": allowFontScaling,
        "onLayout": fromOption(onLayout),
        "onLongPress": fromOption(onLongPress),
        "onPress": fromOption(onPress),
        "theme": fromOption(theme),
        "style": fromOption(style),
        "testID": fromOption(testID),
      },
    children,
  );