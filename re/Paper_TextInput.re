[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "TextInput";

let make =
    (
      ~disabled: bool=false,
      ~label: option(string)=?,
      ~placeholder: option(string)=?,
      ~underlineColor: option(string)=?,
      ~multline: bool=false,
      ~numberOfLines: option(int)=?,
      ~value: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onChangeText: option(string => unit)=?,
      ~onFocus: option(unit => unit)=?,
      ~onBlur: option(unit => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "disabled": Js.Boolean.to_js_boolean(disabled),
          "label": from_opt(label),
          "placeholder": from_opt(placeholder),
          "underlineColor": from_opt(underlineColor),
          "multline": Js.Boolean.to_js_boolean(multline),
          "numberOfLines": from_opt(numberOfLines),
          "value": from_opt(value),
          "theme": from_opt(theme),
          "style": from_opt(style),
          "onChangeText": from_opt(onChangeText),
          "onFocus": from_opt(onFocus),
          "onBlur": from_opt(onBlur)
        }
      ),
    children
  );
