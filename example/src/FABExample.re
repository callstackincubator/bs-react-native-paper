open BsReactNative;
open Navigation;
open BsReactNativePaper;
open Paper;

module Styles = {
  open Style;

  let container =
    style([
      flex(1.0),
      padding(Pt(4.)),
      backgroundColor(String("#eeeeee")),
    ]);

  let row = style([flex(1.), justifyContent(Center), alignItems(Center)]);

  let fab = style([margin(Pt(8.))]);
  let fabStyle = style([backgroundColor(String("#6200EE"))]);
};

type state = {visible: bool};

type action =
  | ToggleVisible(bool);

let component = ReasonReact.reducerComponent("FAB example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {visible: false},
  reducer: (action, _state) =>
    switch (action) {
    | ToggleVisible(visible) => ReasonReact.Update({visible: visible})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="FAB example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <View style=Styles.row>
                 <FAB
                   small=true
                   style=Styles.fab
                   onPress={_event => ()}
                   icon={Icon.Name("add")}
                 />
                 <FAB
                   icon={Icon.Name("favorite")}
                   style=Styles.fab
                   onPress={_event => ()}
                 />
                 <FAB
                   icon={Icon.Name("done")}
                   label="Extended FAB"
                   style=Styles.fab
                   onPress={_event => ()}
                 />
                 <FAB
                   icon={Icon.Name("cancel")}
                   label="Disabled FAB"
                   style=Styles.fab
                   onPress={_event => ()}
                   disabled=true
                 />
                 <Portal>
                   <FAB.Group
                     open_={self.state.visible}
                     onStateChange={
                       _fabState =>
                         self.send(ToggleVisible(!self.state.visible))
                     }
                     icon={
                       self.state.visible ?
                         Icon.Name("today") : Icon.Name("add")
                     }
                     fabStyle=Styles.fabStyle
                     actions=[|
                       FAB.Group.fabAction(
                         ~icon=
                           Icon.Element(
                             Icon.renderIcon((props: Icon.iconProps) =>
                               <RNIcons.MaterialIcons
                                 name=`_add
                                 size={props.size}
                               />
                             ),
                           ),
                         ~onPress=() => (),
                         (),
                       ),
                       FAB.Group.fabAction(
                         ~icon=Icon.Name("star"),
                         ~label="Star",
                         ~onPress=() => (),
                         (),
                       ),
                       FAB.Group.fabAction(
                         ~icon=Icon.Name("email"),
                         ~label="Email",
                         ~onPress=() => (),
                         (),
                       ),
                       FAB.Group.fabAction(
                         ~icon=Icon.Name("notifications"),
                         ~label="Notifications",
                         ~onPress=() => (),
                         (),
                       ),
                     |]
                   />
                 </Portal>
               </View>
             </View>
         }
    </StackNavigator.Screen>,
};
