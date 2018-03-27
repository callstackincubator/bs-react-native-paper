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
          "elipsizeMode": Js.Undefined.fromOption(elipsizeMode),
          "nativeID": Js.Undefined.fromOption(nativeID),
          "numberOfLines": Js.Undefined.fromOption(numberOfLines),
          "pressRetentionOffset": Js.Undefined.fromOption(pressRetentionOffset),
          "allowFontScaling": Js.Boolean.to_js_boolean(allowFontScaling),
          "onLayout": Js.Undefined.fromOption(onLayout),
          "onLongPress": Js.Undefined.fromOption(onLongPress),
          "onPress": Js.Undefined.fromOption(onPress),
          "theme": Js.Undefined.fromOption(theme),
          "style": Js.Undefined.fromOption(style)
        }
      ),
    children
  );
