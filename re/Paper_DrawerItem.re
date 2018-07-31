[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "DrawerItem";

let make =
    (
      ~label: option(string),
      ~icon: option(ReasonReact.reactElement)=?,
      ~active: bool=false,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~color: option(string)=?,
      ~onPress: option(Rebolt.RNEvent.NativeEvent.t => unit)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "label": fromOption(label),
          "icon": fromOption(icon),
          "active": active,
          "color": fromOption(color),
          "onPress": fromOption(onPress),
          "theme": fromOption(theme),
        }
      ),
    children,
  );
