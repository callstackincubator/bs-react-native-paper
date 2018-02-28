module Button = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Button";

  let make =
    (
      ~disabled: option(bool)=?,
      ~compact: option(bool)=?,
      ~raised: option(bool)=?,
      ~primary: option(bool)=?,
      ~loading: option(bool)=?,
      ~dark: option(bool)=?,
      ~icon: option(ReasonReact.reactElement)=?,
      ~color: option(string)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~theme: option(Js.t({..}))=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "disabled": from_opt(disabled),
          "compact": from_opt(compact),
          "raised": from_opt(raised),
          "primary": from_opt(primary),
          "loading": from_opt(loading),
          "dark": from_opt(dark),
          "icon": from_opt(icon),
          "color": from_opt(color),
          "style": from_opt(style),
          "theme": from_opt(theme), 
          "onPress": from_opt(onPress)
        }
      ),
    children
  );
};