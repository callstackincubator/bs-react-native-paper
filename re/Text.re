open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Text";

let make =
    (
      ~selectable: bool=false,
      ~acessible: bool=false,
      ~elipsizeMode: option(string)=?,
      ~nativeID: option(string)=?,
      ~numberOfLines: option(int)=?,
      ~pressRetentionOffset: option(Js.t({..}))=?,
      ~allowFontScaling: bool=false,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onLayout: option(unit => unit)=?,
      ~onLongPress: option(unit => unit)=?,
      ~onPress: option(unit => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "selectable": Js.Boolean.to_js_boolean(selectable),
          "acessible": Js.Boolean.to_js_boolean(acessible),
          "elipsizeMode": from_opt(elipsizeMode),
          "nativeID": from_opt(nativeID),
          "numberOfLines": from_opt(numberOfLines),
          "pressRetentionOffset": from_opt(pressRetentionOffset),
          "allowFontScaling": Js.Boolean.to_js_boolean(allowFontScaling),
          "onLayout": from_opt(onLayout),
          "onLongPress": from_opt(onLongPress),
          "onPress": from_opt(onPress),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );
