module Item = {
  [@bs.module "react-native-paper"] [@bs.scope "Drawer"]
  external reactClass: ReasonReact.reactClass = "Item";

  let make =
      (
        ~label: string,
        ~icon: option(ReasonReact.reactElement)=?,
        ~active: bool=false,
        ~theme: option(Paper_ThemeProvider.appTheme)=?,
        ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
        ~style: option(BsReactNative.Style.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Null_undefined.{
          "label": label,
          "icon": fromOption(icon),
          "active": active,
          "onPress": fromOption(onPress),
          "theme": fromOption(theme),
          "style": fromOption(style),
        },
      children,
    );
};

module Section = {
  [@bs.module "react-native-paper"] [@bs.scope "Drawer"]
  external reactClass: ReasonReact.reactClass = "Section";

  let make =
      (~title: option(string)=?, ~theme: option(Js.t({..}))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Null_undefined.{
          "title": fromOption(title),
          "theme": fromOption(theme),
        },
      children,
    );
};
